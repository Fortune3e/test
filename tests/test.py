import subprocess
import os.path

from correct_infil import CorrectInfil
from mag_dat import MagDat

def testCreatedInfil(correctIn, fileName):
    dirFileName = f"./{fileName}"
    if(os.path.isfile(dirFileName)):
        with open(fileName) as file:
            lines = file.readlines()
            if(len(lines) != correctIn.number_of_lines):
                print(f"Wrong number of lines in {fileName} file")
                exit(1)
            for line in range(0,len(lines)):
                if(len(lines[line].split()) != correctIn.linesValues[line]):
                    print(f"Wrong number of values in {line+1}. line in {fileName} file")
                    exit(1)
    else:
        print(f"{fileName} file not exists or name of infil file is wrong")
        exit(1)
    print(f"Created {fileName} file is in correct format")

correctInfil = CorrectInfil("./correct_infil")
correctInfil.read_correct_infil()

correctIntraj = CorrectInfil("./correct_intraj")
correctIntraj.read_correct_infil()

correctInmag = CorrectInfil("./correct_inmag")
correctInmag.read_correct_infil()

subprocess.run(["./InfilGenerator", "./caspoloha.dat0", "./infil0"])
subprocess.run(["./InfilGenerator", "./trajectory.dat0", "./intraj0", "trajectory"])
subprocess.run(["./InfilGenerator", "./mag.dat0", "./magInfil/inmag0", "mag"])

testCreatedInfil(correctInfil, "./infil0_0")
testCreatedInfil(correctIntraj, "./intraj0_0")

magDat = MagDat("./mag.dat0")
magDat.read_magData()
for fileIndex in range(0,magDat.numberOfHours):
    testCreatedInfil(correctInmag, f"./magInfil/inmag0_{fileIndex}")
