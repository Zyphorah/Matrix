#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;
using namespace sf;

void rotation(std::vector<sf::Vector2f>& vecteurs, float angleDeg) 
{
    float angleRad = angleDeg * M_PI / 180; // Conversion de degrés en radians
    float sinAngle = sin(angleRad);
    float cosAngle = cos(angleRad);

    for (auto& vecteur : vecteurs) 
    {
        float x = vecteur.x;
        float y = vecteur.y;
        vecteur.x = cosAngle * x - sinAngle * y;
        vecteur.y = sinAngle * x + cosAngle * y;
    }
}

void dessinerVecteur(vector<Vector2f>&matrixCube,RenderWindow& window)
{
    for (int i = 0; i < matrixCube.size() - 1; i++) 
        {
            sf::Vertex line[] = 
            {
                sf::Vertex(matrixCube[i], sf::Color::White),
                sf::Vertex(matrixCube[i + 1], sf::Color::White)
            };

            window.draw(line, 2, sf::Lines);
        }
}

void loopWindow(RenderWindow& window,vector<Vector2f>& matrixCube)
{
     Event event;
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        
        rotation(matrixCube,1);
        dessinerVecteur(matrixCube,window);
       

        window.display();
    }
}

int main()
{

   vector<Vector2f> matrixCube
    {
        {100, 100}, // Point A
        {300, 100}, // Point B
        {300, 300}, // Point C
        {100, 300}, // Point D
        {100, 99}  // Retour au Point A pour fermer le carré
    };
   
    RenderWindow window(VideoMode(1100,600),"Matrix");
    
    window.setFramerateLimit(120);
    loopWindow(window,matrixCube);

   

}