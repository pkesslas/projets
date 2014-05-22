#
# Donkey Kong Labyrinthe
#
# pkesslas - 2014
#

import sys
import pygame
from pygame.locals import *

class Game:
    win = pygame.display.set_mode((450, 450))
    pygame.display.set_caption("Donkey Kong Labyrint")
    bg = pygame.image.load("fond.bmp").convert()
    wall = pygame.image.load("mur.bmp").convert_alpha()
    start = pygame.image.load("depart.bmp").convert_alpha()
    end = pygame.image.load("arrivee.bmp").convert_alpha()
    dk_d = pygame.image.load("dk_bas.bmp").convert_alpha()
    dk_u = pygame.image.load("dk_haut.bmp").convert_alpha()
    dk_r = pygame.image.load("dk_droite.bmp").convert_alpha()
    dk_l = pygame.image.load("dk_gauche.bmp").convert_alpha()
    menu = pygame.image.load("accueil.bmp").convert_alpha()
    map = list()
    pos_x = 0
    pos_y = 0
    dk_or = 1

    def create_map(self, fd):
        file = open(fd)
        line = file.read().split('\n')
        return line

    def print_map(self):
        for i in range(15):
            for j in range(15):
                if int(self.map[i][j]) == 1:
                    self.win.blit(self.wall, (j * 30, i * 30))
                elif int(self.map[i][j]) == 2:
                    self.win.blit(self.start, (j * 30, i * 30))
                    s_pos = (i * 30, j * 30)
                elif int(self.map[i][j]) == 3:
                    self.win.blit(self.end, (j * 30, i * 30))
        return s_pos

    def recup_end(self):
        for i in range(15):
            for j in range(15):
                if int(self.map[i][j]) == 3:
                    end = (j * 30, i * 30)
        return end

    def move_sprite(self, or_dir):
        if or_dir == 1:
            self.dk_or = 1
            self.win.blit(self.bg, (0, 0))
            self.print_map()
            self.win.blit(self.dk_r, (self.pos_x, self.pos_y))
        elif or_dir == 2:
            self.dk_or = 2
            self.win.blit(self.bg, (0, 0))
            self.print_map()
            self.win.blit(self.dk_u, (self.pos_x, self.pos_y))
        elif or_dir == 3:
            self.dk_or = 3
            self.win.blit(self.bg, (0, 0))
            self.print_map()
            self.win.blit(self.dk_d, (self.pos_x, self.pos_y))
        elif or_dir == 4:
            self.dk_or = 4
            self.win.blit(self.bg, (0, 0))
            self.print_map()
            self.win.blit(self.dk_l, (self.pos_x, self.pos_y))
        pygame.display.flip()

    def move(self):
        self.win.blit(self.bg, (0, 0))
        self.print_map()
        if self.dk_or == 1:
            self.pos_x += 30
            self.win.blit(self.dk_r, (self.pos_x, self.pos_y))
        elif self.dk_or == 2:
            self.pos_y -= 30
            self.win.blit(self.dk_u, (self.pos_x, self.pos_y))
        elif self.dk_or == 3:
            self.pos_y += 30
            self.win.blit(self.dk_d, (self.pos_x, self.pos_y))
        elif self.dk_or == 4:
            self.pos_x -= 30
            self.win.blit(self.dk_l, (self.pos_x, self.pos_y))
        pygame.display.flip()

    def can_i_move(self):
        x = int(self.pos_y / 30)
        y = int(self.pos_x / 30)
        if self.dk_or == 3 and int(self.map[x + 1][y]) != 1:
            return True
        elif self.dk_or == 4 and int(self.map[x][y - 1]) != 1:
            return True
        elif self.dk_or == 1 and int(self.map[x][y + 1]) != 1:
            return True
        if self.dk_or == 2 and int(self.map[x - 1][y]) != 1:
            return True
        else:
            return False

    def play(self, choice):
        if choice == 1:
            self.map = self.create_map("map_1.map")
        elif choice == 2:
            self.map = self.create_map("map_2.map")
        self.win.blit(self.bg, (0, 0))
        start = self.print_map()
        self.pos_x = start[0]
        self.pos_y = start[1]
        self.win.blit(self.dk_r, (self.pos_x, self.pos_y))
        pygame.display.flip()
        end = self.recup_end()
        win = False
        pygame.key.set_repeat(40, 30)
        while win == False:
            pygame.time.Clock().tick(10)
            for event in pygame.event.get():
                if event.type == QUIT:
                    exit()
                if event.type == KEYDOWN and event.key == K_ESCAPE:
                    exit()
                elif event.type == KEYDOWN and event.key == K_RIGHT:
                    if self.dk_or != 1:
                        self.move_sprite(1)
                    elif self.dk_or == 1 and self.can_i_move():
                        self.move()
                elif event.type == KEYDOWN and event.key == K_UP:
                    if self.dk_or != 2:
                        self.move_sprite(2)
                    elif self.dk_or == 2 and self.can_i_move():
                        self.move()
                elif event.type == KEYDOWN and event.key == K_DOWN:
                    if self.dk_or != 3:
                        self.move_sprite(3)
                    elif self.dk_or == 3 and self.can_i_move():
                        self.move()
                elif event.type == KEYDOWN and event.key == K_LEFT:
                    if self.dk_or != 4:
                        self.move_sprite(4)
                    elif self.dk_or == 4 and self.can_i_move():
                        self.move()
            if self.pos_x == end[0] and self.pos_y == end[1]:
                win = True



