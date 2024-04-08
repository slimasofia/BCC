import pygame
import random

# Definição das cores
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

# Definição dos estados
SUSCEPTIBLE = 10
INFECTED = 1
RECOVERED = 2

class Person:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.state = SUSCEPTIBLE

    def draw(self, screen):
        if self.state == SUSCEPTIBLE:
            pygame.draw.circle(screen, BLUE, (self.x, self.y), 5)
        elif self.state == INFECTED:
            pygame.draw.circle(screen, RED, (self.x, self.y), 5)
        elif self.state == RECOVERED:
            pygame.draw.circle(screen, GREEN, (self.x, self.y), 5)

    def infect(self):
        self.state = INFECTED

class Simulation:
    def __init__(self, population_size, width, height):
        self.population = [Person(random.randint(0, width), random.randint(0, height)) for _ in range(population_size)]
        self.population[random.randint(0, population_size - 1)].infect()  # Infectando uma pessoa aleatória
        self.width = width
        self.height = height

    def update(self):
        for person in self.population:
            if person.state == SUSCEPTIBLE:
                for other_person in self.population:
                    if other_person.state == INFECTED and random.random() < 0.1:  # Taxa de propagação
                        person.infect()
                        break

    def draw(self, screen):
        screen.fill(WHITE)
        for person in self.population:
            person.draw(screen)
        pygame.display.flip()

def main():
    pygame.init()
    width, height = 800, 600
    screen = pygame.display.set_mode((width, height))
    pygame.display.set_caption('Epidemia')

    simulation = Simulation(100, width, height)
    clock = pygame.time.Clock()

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        simulation.update()
        simulation.draw(screen)
        clock.tick(30)

    pygame.quit()

if __name__ == '__main__':
    main()
