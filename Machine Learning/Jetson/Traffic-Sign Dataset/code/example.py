import cv2
import os
from parseSignAnnotations import parseSignAnnotations

def displaySigns (img,signs):
    SignsNr=len(signs)
    if (SignsNr>0):
        if(signs[0].type == ""):
            SignsNr=0
            return SignsNr
        
    for i in range(SignsNr):
        s=signs[i]
        bb=s.BB  #s.BB = [TLx, TLy, BRx, BRy]    
        if s.type == "MISC_SIGNS" :
            print(s.type)
            #cv2.putText(img, text=s.type, org=(bb[1],bb[2]), cv2.FONT_HERSHEY_SIMPLEX, scale = 1, color=(255,0,0), thickness=2,lineType=cv2.LINE_AA)

        else:
                
            img = cv2.line(img,(bb[0],bb[1]),(bb[2],bb[1]),(255,0,0),2)
            img = cv2.line(img,(bb[0],bb[1]),(bb[0],bb[3]),(255,0,0),2)
            img = cv2.line(img,(bb[0],bb[3]),(bb[2],bb[3]),(255,0,0),2)
            img = cv2.line(img,(bb[2],bb[1]),(bb[2],bb[3]),(255,0,0),2)
            
            #Write text in upper left corner
            #cv2.putText(img, s.type, (bb[1],bb[2]), cv2.FONT_HERSHEY_SIMPLEX, scale = 1, (255,0,0), 2,cv2.LINE_AA)
            #cv2.putText(img, s.name, (bb[3],bb[4]), cv2.FONT_HERSHEY_SIMPLEX, scale = 1, (255,0,0), 2,cv2.LINE_AA)    
            cv2.imshow("image", img)
            k = cv2.waitKey(0)
            if k == 27 :
                cv2.destroyAllWindws()
                exit()
            elif k == ord("n") :
                return

imagePath = "../Images"
annotation = "annotations1.txt"

content = parseSignAnnotations(annotation)

N = len(content)

for i in range(N) :
    imgName = os.path.join(imagePath, content[i].name)
    try :
        img = cv2.imread(imgName)
    except :
        print("Error Loading the image")
    
    displaySigns(img, content[i].signs)

cv2.destroyAllWindws()

# import cv2
# img = cv2.imread("1277381671Image000012.jpg")
# cv2.putText(img, s.type, (605,547), cv2.FONT_HERSHEY_SIMPLEX, fontScale = 1, (255,0,0))
# cv2.imshow("aaa", img)
# k = cv2.waitKey(0)
# if k == 27 :
#     cv2.destroyAllWindws()


