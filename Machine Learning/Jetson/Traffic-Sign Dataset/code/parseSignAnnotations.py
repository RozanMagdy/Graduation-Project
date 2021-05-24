class Sign :
    def __init__(self, MISC_SIGNS = False):
        if not MISC_SIGNS:
            self.type        = ""
            self.name        = ""
            self.status      = ""
            self.BB          = []
            self.center      = []
            self.size        = 0.0
            self.aspectRatio = 0.0
            self.width       = 0.0
            self.height      = 0.0
        else :
            self.type        = "MISC_SIGNS"
            self.name        = "N/A"
            self.status      = "N/A"
            self.BB          = [-1, -1, -1, -1]
            self.center      = [-1, -1]
            self.size        = 0
            self.aspectRatio = 0
            self.width       = 0
            self.height      = 0
    
    def compute(self):
        Cx = (self.BB[0] + self.BB[2]) // 2
        Cy = (self.BB[1] + self.BB[3]) // 2
        self.center = [Cx, Cy]

        self.width  = abs(self.BB[0] - self.BB[2])
        self.height = abs(self.BB[1] - self.BB[3])
        self.size = min(self.width, self.height) ** 2
       #self.size = self.width * self.height

        self.aspectRatio = self.width / self.height


class Image :
    imageNr = 0
    def __init__(self, imageName) :
        self.name  = imageName
        self.signs = []
        Image.imageNr += 1


def parseSignAnnotations(filename) :
    f = open(filename, "r")
    
    data = []

    for line in f:
        line = line.strip()
        idx_nameEnd = line.index(":")
        imageName = line[:idx_nameEnd]
        img = Image(imageName)
        line = line[idx_nameEnd+1:]
        
        idx_signEnd = line.find(";")
        while len(line) != 0 and idx_signEnd != -1 :
            if line[:idx_signEnd] == "MISC_SIGNS" :
                s = Sign(MISC_SIGNS = True)
                img.signs.append(s)

                line = line[idx_signEnd+1:]
            else :
                s = Sign()

                #Visibility
                idx_comma = line.index(",")
                visibility = line[:idx_comma]
                s.status = visibility
                line = line[idx_comma+2:]

                #Bunding Box
                #Bottm Right
                idx_comma = line.index(",")
                BRx = int(float(line[:idx_comma]))
                line = line[idx_comma+2:]

                idx_comma = line.index(",")
                BRy = int(float(line[:idx_comma]))
                line = line[idx_comma+2:]

                #Top Left
                idx_comma = line.index(",")
                TLx = int(float(line[:idx_comma]))
                line = line[idx_comma+2:]

                idx_comma = line.index(",")
                TLy = int(float(line[:idx_comma]))
                line = line[idx_comma+2:]

                s.BB = [TLx, TLy, BRx, BRy]

                #Type
                idx_comma = line.index(",")
                s.type = line[:idx_comma]
                line = line[idx_comma+2:]

                #Name
                idx_signEnd = line.find(";")
                s.name = line[:idx_signEnd]
                
                s.compute()
                img.signs.append(s)

                line = line[idx_signEnd+1:]
                idx_signEnd = line.find(";")

            data.append(img)

    f.close()
    return data
        
