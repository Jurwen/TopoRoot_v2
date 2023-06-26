# Whorl and Soil Plane Detection


presents a complete, automatic, and high through-put phenotyping system based on TopoRoot using a single 3D X-ray CT scan of excavated maize root crowns. We build our computational methods for whorls and soil planes upon TopoRoot’s pipeline and its hierarchical skeletons. 

TopoRoot: A method for computing hierarchy and fine-grained traits of maize roots from X-ray CT images

https://www.biorxiv.org/content/10.1101/2021.08.24.457522v1

# Installation and Execution

Please download the .exe file and put it at the same folder with the TopoRoot.exe

The program takes one input file, tims incorrect vertex data within the input file, and outputs an annotation file used for GUI's visualization of whorls and soil planes.

The input file is in such format. Find *_skel_fixed.ply in the ouput file, and put it at the second place in the command line. 

# Experiment Data

The data used for ground truth validation in our manuscript can be found here:
There are two new datasets: 
NAM: https://wustl.app.box.com/folder/214518933853
PlantHaven2021: https://wustl.app.box.com/folder/214380610514
PlantHaven2020 can be found in TopoRoot.

# Graphical User Interface

The graphical user interface can be found at this link: 
https://github.com/Jurwen/RootGUI


