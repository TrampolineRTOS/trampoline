# To do to configure the script of the application:
#	1- Set the path to the goil templates directory 	
# 	2- Modify the name of the oil file when calling goil command
#	3- Modify the name of local directory created to save the generated file (its name is the same as the oil file)  

# Add paths to find goil and bash commands
export PATH=/C/MinGW/msys/1.0/bin:/C/Users/mf.sassi/Porting_Tranpoline_Project/Trampoline/trampoline-r1641/goilv2/project-codeblocks-windows:$PATH

PROJDIRPATH_WINDOWS = $(echo $PROJDIRPATH | tr '\' '/')	

# Delete generated and copied files of the previous application
rm -R $(echo $PROJDIRPATH | tr '\' '/')/Goil_Files_Generation/Trampoline_Application #/*.{c,s,S,h}
rm $(echo $PROJDIRPATH | tr '\' '/')/Trampoline_PPC_Sources/Trampoline_Generated_Sources/*.{c,s,S}

# Call goil tool to generate files 
goil -t=ppc/MPC5674 --templates=../../../../../goilv2/templates Trampoline_Application.oil

# Create directories where to save generated headers and sources
mkdir $(echo $PROJDIRPATH | tr '\' '/')/Project_Headers/Trampoline_Generated_Headers
mkdir $(echo $PROJDIRPATH | tr '\' '/')/Trampoline_PPC_Sources/Trampoline_Generated_Sources

# Copied the generated files to the correspondent folders in the project
cp ./Trampoline_Application/*.h $(echo $PROJDIRPATH | tr '\' '/')/Project_Headers/Trampoline_Generated_Headers
cp ./Trampoline_Application/*.{c,s,S} $(echo $PROJDIRPATH | tr '\' '/')/Trampoline_PPC_Sources/Trampoline_Generated_Sources

# Delete the local created directory to avoid compilation errors
rm -R $(echo $PROJDIRPATH | tr '\' '/')/Goil_Files_Generation/Trampoline_Application