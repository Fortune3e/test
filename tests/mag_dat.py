from datetime import datetime

class MagDat():
    fileName = ""
    numberOfHours = 0

    def __init__(self, fileName):
        self.fileName = fileName
        self.values = []

    def read_magData(self):
        with open(self.fileName) as file:
            lines = file.readlines()
            self.number_of_lines = len(lines)
            for line in lines:
                self.values.append(line.split())
        inputDateStart = self.values[0][0]
        inputTimeStart = self.values[0][1]
        inputDateEnd = self.values[0][2]
        inputTimeEnd = self.values[0][3]
        intervalDur = int(self.values[0][4])
        if(intervalDur == 0):
            intervalDur = 1
        date = inputDateStart + " " + inputTimeStart
        endDate = inputDateEnd + " " + inputTimeEnd

        date_format_str = '%Y-%m-%d %H:%M:%S'

        dateStart = datetime.strptime(date, date_format_str)
        dateEnd =   datetime.strptime(endDate, date_format_str)

        diff = dateEnd - dateStart

        self.numberOfHours = round((diff.total_seconds() / 3600) / intervalDur) + 1
