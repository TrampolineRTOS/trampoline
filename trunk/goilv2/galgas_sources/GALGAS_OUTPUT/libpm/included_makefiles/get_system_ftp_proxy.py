#!/usr/bin/python
# -*- coding: utf-8 -*-
 
import urllib
 
proxies = urllib.getproxies ()

if 'ftp' in proxies :
  print "--proxy " + proxies ['ftp']
