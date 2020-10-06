#include "glwidget.h"

#include "cs123_lib/resourceloader.h"
#include "cs123_lib/errorchecker.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <iostream>

#include "settings.h"

#define PI 3.14159265f

GLWidget::GLWidget(QGLFormat format, QWidget *parent)
    : QGLWidget(format, parent), m_angleX(0), m_angleY(0.5f), m_zoom(10.f)
{}

GLWidget::~GLWidget()
{}

void GLWidget::initializeGL() {
    ResourceLoader::initializeGlew();
    resizeGL(width(), height());

    glEnable(GL_DEPTH_TEST);

    // Set the color to set the screen when the color buffer is cleared.
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Create sky
    m_sky_program = ResourceLoader::createShaderProgram(":/shaders/texture.vert", ":/shaders/texture.frag");
    m_sky.init();

    // Create terrain
    m_program = ResourceLoader::createShaderProgram(":/shaders/shader.vert", ":/shaders/shader.frag");
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            m_terrain.init(i,j);
        }
    }

    rebuildMatrices();
}

/**
 * Recreates terrain. Called when settings are changed.
 */
void GLWidget::updateTerrain() {
    m_terrain.updateSettings(settings.scale, settings.octaves);
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            m_terrain.init(i,j);
        }
    }
}

void GLWidget::updateSky() {
    m_sky.init();
}

/**
 * Exports the terrain geometry as an .obj file.
 */
void GLWidget::exportTerrain() {
    m_terrain.toOBJ();
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind the terrain shader program
    glUseProgram(m_program);
    // Set uniforms
    glUniformMatrix4fv(glGetUniformLocation(m_program, "model"), 1, GL_FALSE, glm::value_ptr(m_model));
    glUniformMatrix4fv(glGetUniformLocation(m_program, "view"), 1, GL_FALSE, glm::value_ptr(m_view));
    glUniformMatrix4fv(glGetUniformLocation(m_program, "projection"), 1, GL_FALSE, glm::value_ptr(m_projection));

    // bind the uniform samplers to texture units
    glUniform1i(glGetUniformLocation(m_program, "rock_tex"), 0);
    glUniform1i(glGetUniformLocation(m_program, "grass_tex"), 1);
    glUniform1i(glGetUniformLocation(m_program, "rock_normalMap"),  2);
    glUniform1i(glGetUniformLocation(m_program, "grass_normalMap"),  3);


    // bind integer uniforms for whether texture mapping and use fog are selected in UI
    if (settings.useTextureMapping) {
        glUniform1i(glGetUniformLocation(m_program, "useTextureMap"), 1);
    } else {
        glUniform1i(glGetUniformLocation(m_program, "useTextureMap"), 0);
    }
    if (settings.useFog) {
        glUniform1i(glGetUniformLocation(m_program, "useFog"), 1);
    } else {
        glUniform1i(glGetUniformLocation(m_program, "useFog"), 0);
    }

    glUniform1i(glGetUniformLocation(m_program, "sky"), settings.sky);
    // Draw terrain
    m_terrain.draw();
    // Unbind shader program
    glUseProgram(0);


    // bind the sky shader program
    glUseProgram(m_sky_program);
    // Set uniforms
    glUniformMatrix4fv(glGetUniformLocation(m_sky_program, "model"), 1, GL_FALSE, glm::value_ptr(m_model));
    glUniformMatrix4fv(glGetUniformLocation(m_sky_program, "view"), 1, GL_FALSE, glm::value_ptr(m_view));
    glUniformMatrix4fv(glGetUniformLocation(m_sky_program, "projection"), 1, GL_FALSE, glm::value_ptr(m_projection));
    glUniform1i(glGetUniformLocation(m_sky_program, "sky_tex"), 2);
    if (settings.useTextureMapping) {
        glUniform1i(glGetUniformLocation(m_sky_program, "useTextureMap"), 1);
    } else {
        glUniform1i(glGetUniformLocation(m_sky_program, "useTextureMap"), 0);
    }
    // Draw the sky
    m_sky.draw();
    // unbind the program
    glUseProgram(0);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    rebuildMatrices();
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
    m_prevMousePos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    m_angleX += 10 * (event->x() - m_prevMousePos.x()) / (float) width();
    m_angleY += 10 * (event->y() - m_prevMousePos.y()) / (float) height();
    m_prevMousePos = event->pos();
    // Restrict mouse events that will take you underneath the terrain
    if (m_angleY >= 0.1) {
        rebuildMatrices();
    } else {
        m_angleY = 0.1;
    }


}

void GLWidget::wheelEvent(QWheelEvent *event) {
    // Restrict wheel events that will take you outside of the skydome
    if (m_zoom - (event->delta() / 100.f) <= 15.0) {
        m_zoom -= event->delta() / 100.f;
        rebuildMatrices();
    }
}

void GLWidget::rebuildMatrices() {
    m_model = glm::mat4(1.f);
    m_view = glm::translate(glm::vec3(0, 0, -m_zoom)) *
             glm::rotate(m_angleY, glm::vec3(1,0,0)) *
             glm::rotate(m_angleX, glm::vec3(0,1,0));
    m_projection = glm::perspective(0.8f, (float)width()/height(), 0.1f, 100.f);
    update();
}
