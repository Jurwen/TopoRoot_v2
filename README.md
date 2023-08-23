# TopoRoot+ : Computing Whorl and Soil Line Traits of Maize Roots from CT Imaging

# Introduction

TopoRoot+ presents a complete, automatic, and high through-put phenotyping system based on TopoRoot using a single 3D X-ray CT scan of excavated maize root crowns. We build our computational methods for whorls and soil planes upon TopoRoot’s pipeline and its hierarchical skeletons. 

TopoRoot: A method for computing hierarchy and fine-grained traits of maize roots from X-ray CT images

https://www.biorxiv.org/content/10.1101/2021.08.24.457522v1

# Installation and Execution

Please download the .exe file and put it at the same folder with the TopoRoot.exe

 TopoRoot+ can be run as follows. The first three arguments are required, while the rest are optional:

TopoRoot_v2.exe --in [input_file] --out [output_file] --S [shape] --K [kernel] --N [neighborhood] --d [downsampling rate] --maxLevel [level]

Mandatory Parameters:

--input: Path to image slices (for instance, D:/samples/image_slices/) or a .raw file. If you're using a .raw file, you must also provide a .dat file using --data [data_file.dat].

--output: Determines the path and filenames for the results. For an argument value like folder/output_filename, the outputs would be:

folder/output_filename.ply (structural skeleton)
folder/output_filename_notes.txt (notes file)
folder/output_filename_metrics.csv (measurement hierarchies)
folder/output_filename.visual.off (Mesh visualization)
--S: Iso-value for shape. This is utilized to generate an initial iso-surface. For more details, refer to the "Selecting shape, kernel, and region" subsection.

Optional Parameters:

--K (suggested, particularly for non-Maize CT purposes): Iso-value for kernel. Refer to the "Selecting shape, kernel, and region" subsection for more information.

--N (suggested, especially for non-Maize CT uses): Iso-value for neighborhood/region.

--d: Rate of downsampling: it balances between execution speed and accuracy. Ideally, pick a rate that yields a 400^3 volume dimension, which usually takes about 5-10 minutes to process. As an example, for a 1600^3 initial image size, a rate of 4 might be suitable.

--maxLevel: Highest level in the hierarchy to calculate characteristics. If this exceeds the root system's present highest hierarchy, it adjusts to that level.

--lowerRadius: Defines the slimmest section's width threshold. Only points above this threshold might be higher (default = 0.15 of the widest point). Adjust this if certain stem sections aren't appearing.

--upperRadius: Sets the threshold for the widest stem section. The identification process for stems starts from points exceeding this value (default is 0.95 for single-stem mode, 0.35 for multi-stem). Adjust this if certain stems aren't detected in multi-stem mode.

Note that this tool only supports maize roots. The accuracy of whorls and soil planes are only verified on maize root samples. It does not support multiple tillers / stems.

# Experiment Data

The data used for ground truth validation in our manuscript can be found here:
There are two new datasets: 
NAM: https://wustl.app.box.com/folder/214518933853

PlantHaven2021: https://wustl.app.box.com/folder/214380610514

PlantHaven2020 can be found in TopoRoot: https://wustl.app.box.com/s/yklsinv5v86est2vxk20bwt8e6inq7l0

# Graphical User Interface

The graphical user interface can be found at this link: 
https://github.com/Jurwen/RootGUI

# Understanding the Output

Our workflow generates a trait file in .csv format, which compiles statistics for all analyzed samples. Additionally, there are visual representation files that illustrate the skeletal hierarchy, which come in .ply, .off, and .txt formats.

Details of the Trait File

For each analyzed sample, we offer the subsequent traits:

For every hierarchy tier within the plant's structure (typically tiers 1-3; refer to settings), combined lateral roots (tiers >= 2), and a collective analysis of all roots (across all tiers), we provide:

Count of roots

Mean root span

Cumulative root span

Mean root width

Mean root twist or deviation

Root tip inclination

Root emergence inclination

Central point inclination

Child root count

Length of the stem

Diameter of the stem

Count of whorls

Count of roots both above and beneath the ground level

Whorl count both above and below the ground

The two most extended distances between whorls


# Downsampling

If images boast a resolution exceeding approximately 500^3, it's advised to reduce their resolution before utilizing the tool. Various software options like ImageJ are available for this purpose. 

