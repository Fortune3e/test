class CorrectInfil():
    number_of_lines = 0
    fileName = ""

    def __init__(self, fileName):
        self.fileName = fileName
        self.linesValues = []

    def read_correct_infil(self):
        with open(self.fileName) as file:
            lines = file.readlines()
            self.number_of_lines = len(lines)
            for line in lines:
                self.linesValues.append(len(line.split()))