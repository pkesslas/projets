#
# Donkey Kong Labyrinthe
#
# pkesslas - 2014
#

import pygame
from game_class import *
from pygame.locals import *
import sys

import PIL

pygame.init()

game = Game()

while 1:
    game.win.blit(game.menu, (0, 0))
    pygame.display.flip()
    for event in pygame.event.get():
        if event.type == QUIT:
            exit()
        if event.type == KEYDOWN and event.key == K_ESCAPE:
            exit()
        if event.type == KEYDOWN and event.key == K_F1:
            game.play(1)
        elif event.type == KEYDOWN and event.key == K_F2:
            game.play(2)
