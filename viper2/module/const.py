#######
# Constant for drawings
#######

# Colors
red = (248, 34, 0)
yellow = (255, 227, 24)
green = (0, 152, 6)
black = (0, 0, 0)
white = (255, 255, 255)
background_color = 231, 229, 210

# Screen
screen_width = 1400
screen_height = 800

# Devices
border_line = 5

# Button
button_width = 100
button_height = 80

# DAC
dac_width = 360
dac_height = 320
max_volt = 140
max_dac = 2
max_time = 350

# LCD
lcd_width = 200
lcd_height = 120

# Server
lcdserver_width = 400
lcdserver_height = 400
robot_size = 4
#robot_light = 4

####
# Constant for "key" pressed
#######

import pygame

from pygame.locals import QUIT, MOUSEBUTTONDOWN, MOUSEBUTTONUP, MOUSEMOTION, KEYDOWN, KEYUP, USEREVENT
ENTER = pygame.locals.USEREVENT + 0
EXIT = pygame.locals.USEREVENT + 1
BLUR = pygame.locals.USEREVENT + 2
FOCUS = pygame.locals.USEREVENT + 3
CLICK = pygame.locals.USEREVENT + 4
CHANGE = pygame.locals.USEREVENT + 5
OPEN = pygame.locals.USEREVENT + 6
CLOSE = pygame.locals.USEREVENT + 7

# Boolean
true = 1
false = 0

