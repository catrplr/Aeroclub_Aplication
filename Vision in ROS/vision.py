import cv2
import numpy as np
cap=cv2.VideoCapture(0)
while True:
    ret,frame=cap.read()
    width=int(cap.get(3))
    height=int(cap.get(4))
    frame=cv2.flip(frame,1)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray, (7, 7), 0)
    edged = cv2.Canny(blurred, 10, 100)
    contours, hierarchy = cv2.findContours(edged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contour_image = np.zeros_like(edged)
    cv2.drawContours(contour_image, contours, -1, 255, 2)
    for contour in contours:
        area = cv2.contourArea(contour)
        perimeter = cv2.arcLength(contour, True)
        approx = cv2.approxPolyDP(contour, 0.04 * perimeter, True)
        if area < 100 or area>1000:
            continue
        if len(approx) != 3 and len(approx) != 4:
            continue
        if len(approx)== 3:
            cv2.putText(frame, "Triangle", (approx.ravel()[0], approx.ravel()[1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
        elif len(approx) == 4:
            cv2.putText(frame, "Quadrilateral", (approx.ravel()[0], approx.ravel()[1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
    
    cv2.drawContours(frame, [contour], -1, (0, 255, 0), 2)        
    font=cv2.FONT_HERSHEY_SIMPLEX
    moments = cv2.moments(contour)
    cv2.imshow("Original image", frame)
    cv2.imshow("Edged image", contour_image)
    
    if cv2.waitKey(1)==ord('q'):
        break
cap.release()
cv2.destroyAllWindows
