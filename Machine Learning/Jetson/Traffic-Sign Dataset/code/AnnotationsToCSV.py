import os
import csv
from parseSignAnnotations import parseSignAnnotations

annotations1_path =  os.path.join('../data', "annotations1.txt")
annotations2_path =  os.path.join('../data', "annotations2.txt")
content1 = parseSignAnnotations(annotations1_path)
content2 = parseSignAnnotations(annotations2_path)
contents = [content1, content2]
# prefixs  = ['Set1Part0_', 'Set2Part0_']

Multi_Class_Detection = True

csv_name = ''
if Multi_Class_Detection :
    csv_name =  os.path.join('../data', 'Multi_Class_annotations.csv')
else :
    csv_name =  os.path.join('../data', 'Single_Class_annotations.csv')

with open(csv_name, 'w', newline='') as csvfile:
    fieldnames = ["filename", "width",	"height", "class", "xmin", "ymin",	"xmax", "ymax"]
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()
    for i in range(len(contents)): 
        for img in contents[i]: 
            # pre = prefixs[i] 
            for s in img.signs:
                if s.type == "MISC_SIGNS":
                    continue
                if Multi_Class_Detection :
                    writer.writerow({'filename' : img.name,
                                    'width' : s.width, 'height' : s.height,
                                    'class' : s.name,
                                    'xmin' : s.BB[0], 'ymin' : s.BB[1],
                                    'xmax' : s.BB[2], 'ymax' : s.BB[3]})
                else :
                    writer.writerow({'filename' : img.name,
                                    'width' : s.width, 'height' : s.height,
                                    'class' : 'sign',
                                    'xmin' : s.BB[0], 'ymin' : s.BB[1],
                                    'xmax' : s.BB[2], 'ymax' : s.BB[3]})
