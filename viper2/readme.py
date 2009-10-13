Starting Viper2 :

As Viper2 uses pygame (http://www.pygame.org/), the python version of pygame and viper2 has to be the same.
Thus, make sure the interpreter at the beginning of viper2.py has got the same version of the python in the Makefile (PYTHON_inc and MODULE_ldflags).

For example (on MAC OS) : we used pygame-1.9.1release-py2.6-macosx10.5 so, we need to install Python 2.6.2 (http://www.python.org).
After installing python :
 * the interpreter in viper2.py becomes "#!/usr/local/bin/python",
 * PYTHON_inc =  $(shell echo /usr/local/include/python* | tr ' ' '\n' | tail -n1) and
 * MODULE_ldflags += {-L=path_to_python_library} -lpython2.6
