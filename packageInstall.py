import json
from pip._internal import main as pipmain

failedPackages = []

# Reads the json file and returns the dependencies dictionary
def readJson(jsonfilename):
    with open(jsonfilename) as f:
        data = json.load(f)
    
    return data

# Reads the package name and version and installs the package
# If the package installation fails, write the package name to failedPackages list
def installPackage(package, version):
    packagename = package + "==" + version
    print ("Installation Started : ")
    status = pipmain(['install', packagename])
    
    if(status & 1):
        failedPackages.append(package)


# Read the package
data = readJson("packages.json")
totalPackages = len(data)

# Start the package installation
for package in data['Dependencies']:
    print ("Installing version {} for {} package".format(data['Dependencies'][package], package))
    
    version = data['Dependencies'][package]
    installPackage(package, version)

if len(failedPackages) > 0:
    print ("Following packages failed to install")
    for package in failedPackages:
        print ("Failed to install {}".format(package))

else:
    print ("Installation of all packages successful.......")