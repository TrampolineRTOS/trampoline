ECHO OFF
ECHO  
ECHO *** GENERATE BOOTSTRAP LOADER ***
ECHO  
ECHO Assembling Boot167.A66...
..\..\BIN\A166 BOOT167.A66
ECHO  
ECHO Linking Bootstrap Loader...
..\..\BIN\L166 BOOT167.OBJ

