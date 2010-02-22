Starting Viper2 :

* Viper2 can work with pygame or only with the console. You don't have to install pygame if you don't need it, but some examples need it because of the user interaction (App-GBF, App-Robot*). Pygame versions (http://www.pygame.org/) are according to a proper python version (http://www.python.org/)

* Make your own application in config.py with Ecus... (or use one of the examples changing a config-*.py name in config.py).
 
* Select your display in config.py (THIS LINE HAS TO BE IN THE FILE) :
  - pygame -> "dispatch_display = Display(pygame = True)" or "dispatch_display = Display()" (because pygame is enabled by default)  
  - console -> "dispatch_display = Display(pygame = False)"

* Compile Viper2 and Trampoline by "python viper2.py -g -c" (Viper2 check AUTOMATICALLY the python version, modify the include/library path of python in the makefile and make the libraries for Trampoline and Viper2 with "make all"),  by "python viper2.py -a" if you want to use AUTOSAR and by "python viper2.py -v" if you want the verbose mode 

* Launch Viper2 by "python viper2.py" or by "python viper2.py -v" if you want the verbose mode 

* Clean Viper2 (before a commit for example) by "python viper2.py --clean"
