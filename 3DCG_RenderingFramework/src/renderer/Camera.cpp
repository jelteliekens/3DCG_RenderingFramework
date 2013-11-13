#include "Camera.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include "Quaternion.h"

Camera::Camera(AppConfiguration & appCfg) {
	eye.x = std::atof(appCfg["camera.eye.x"].c_str());
	eye.y = std::atof(appCfg["camera.eye.y"].c_str());
	eye.z = std::atof(appCfg["camera.eye.z"].c_str());

	look.x = std::atof(appCfg["camera.look.x"].c_str());
	look.y = std::atof(appCfg["camera.look.y"].c_str());
	look.z = std::atof(appCfg["camera.look.z"].c_str());

	upV.x = std::atof(appCfg["camera.up.x"].c_str());
	upV.y = std::atof(appCfg["camera.up.y"].c_str());
	upV.z = std::atof(appCfg["camera.up.z"].c_str());

	distance = std::atof(appCfg["camera.worldwindow.distance"].c_str());
	width = std::atof(appCfg["camera.worldwindow.width"].c_str());
	height = std::atof(appCfg["camera.worldwindow.height"].c_str());

	calcN();
	initU();
	calcV();
}

void Camera::calcN() {
	n = Vector(look, eye);
	n.normalize();
}

void Camera::initU() {
	u = upV.cross(n);
	u.normalize();
}

void Camera::calcU() {
	u = v.cross(n);
	u.normalize();
}

void Camera::calcV() {
	v = n.cross(u);
}

const double Camera::ANGLE = 5;

void Camera::up() {
	rotate(-ANGLE, u);
	calcN();
	calcV();
}

void Camera::down() {
	rotate(ANGLE, u);
	calcN();
	calcV();
}

void Camera::right() {
	rotate(ANGLE, v);
	calcN();
	calcU();
}

void Camera::left() {
	rotate(-ANGLE, v);
	calcN();
	calcU();
}

void Camera::rotate(double angle, Vector& vector) {
	Quaternion p = Quaternion(eye);
	Quaternion q = Quaternion(angle, vector);
	Quaternion qc = q.conjugate();

	Quaternion pa = q * p * qc;

	eye.x = pa.b;
	eye.y = pa.c;
	eye.z = pa.d;
}

