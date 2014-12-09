#include <towerdefense/computer/Bullet.h>

    void Bullet::setPosX(float posX){
        m_posX=posX;
    }
    void Bullet::setPosY(float posY){
        m_posY=posY;
    }

    void Bullet::setSpeedX(float speX){
        m_speedX=speX;
    }
    void Bullet::setSpeedY(float speY){
        m_speedY=speY;
    }
    void Bullet::setTaille(int tai){
        m_Taille=tai;
    }
    float Bullet::getPosX(){
        return m_posX;
    }
    float Bullet::getPosY(){
        return m_posY;
    }
    float Bullet::getSpeedX(){
        return m_speedX;
    }
    float Bullet::getSpeedY(){
        return m_speedY;
    }
    int Bullet::getTaille(){
        return m_Taille;
    }
