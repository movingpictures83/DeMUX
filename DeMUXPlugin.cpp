#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "DeMUXPlugin.h"

void DeMUXPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void DeMUXPlugin::run() {
   
}

void DeMUXPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; split_libraries_fastq.py";
 command += " -i "+parameters["sequences"];
 command += " -m "+parameters["mapping"];
 if (parameters.count("barcodes") != 0) {
 command += " -b "+parameters["barcodes"];
 }
 if (parameters.count("barcodetype") != 0) {
    command += " --barcode_type "+parameters["barcodetype"];
 }
 //else {
 //   command += " --barcode_type not-barcoded";
 //}
 command += " -o "+file+"; cp "+file+"/*.txt "+file+"/..; cp "+file+"/*.fna "+file+"/..; export PYTHONPATH=OLDPATH"; 
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<DeMUXPlugin> DeMUXPluginProxy = PluginProxy<DeMUXPlugin>("DeMUX", PluginManager::getInstance());
