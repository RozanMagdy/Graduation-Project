def displaySigns (img,signs):
''''
 Displays image   
 Displays the signs given in a signs list.
 Displays bounding box, sign type and additional info

'''
    SignsNr=len(signs)
    if (SignsNr>0):
        if(signs[1].type ==""):
            SignsNr=0
            return SignsNr
        
    for i in range(SignsNr):
        s=signs[i]
        bb=s.BB  #s.BB = [TLx, TLy, BRx, BRy]    
        if (s.type = "MISC_SIGNS" ):
            
            cv2.putText(img, s.type, (bb[1],bb[2]), cv2.FONT_HERSHEY_SIMPLEX, scale = 1, (255,0,0), 2,cv2.LINE_AA)

        else:
                
            img = cv2.line(img,(bb[1],bb[2]),(bb[3],bb[2]),(255,0,0),10)
            img = cv2.line(img,(bb[1],bb[2]),(bb[1],bb[4]),(255,0,0),10)
            img = cv2.line(img,(bb[1],bb[4]),(bb[3],bb[4]),(255,0,0),10)
            img = cv2.line(img,(bb[3],bb[4]),(bb[3],bb[2]),(255,0,0),10)
            
            #Write text in upper left corner
            cv2.putText(img, s.type, (bb[1],bb[2]), cv2.FONT_HERSHEY_SIMPLEX, scale = 1, (255,0,0), 2,cv2.LINE_AA)
            cv2.putText(img, s.name, (bb[3],bb[4]), cv2.FONT_HERSHEY_SIMPLEX, scale = 1, (255,0,0), 2,cv2.LINE_AA)    
            Cv2.imshow(img)
                





