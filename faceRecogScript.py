import face_recognition
import sys
import cv2
import time

try:
    # Hardcoded image path for testing
    image_path = "C:/Users/choua/OneDrive/Bureau/opencvContrib/hama.jpg"
    existing_image = face_recognition.load_image_file(image_path)
    existing_face_encoding = face_recognition.face_encodings(existing_image)

    if len(existing_face_encoding) == 0:
        print("No face encoding found in the image!")
        sys.exit(1)

    existing_face_encoding = existing_face_encoding[0]  # Take the first encoding

    # Initialize webcam
    video_capture = cv2.VideoCapture(0)

    if not video_capture.isOpened():
        print("Error: Could not access the webcam.")
        sys.exit(1)

    print("Webcam initialized. Detection will start in 5 seconds. Press 'q' to quit.")

    # Delay before starting detection
    delay_time = 5  # 5 seconds delay
    start_time = time.time()

    while True:
        # Capture a frame from the webcam
        ret, frame = video_capture.read()

        if not ret:
            print("Error: Failed to grab frame.")
            sys.exit(1)

        # Calculate elapsed time
        elapsed_time = time.time() - start_time

        # Display countdown or message
        if elapsed_time < delay_time:
            countdown = int(delay_time - elapsed_time)
            cv2.putText(frame, f"Starting detection in {countdown}...", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
        else:
            # Start face detection and matching
            face_locations = face_recognition.face_locations(frame)
            face_encodings = face_recognition.face_encodings(frame, face_locations)

            if len(face_encodings) == 0:
                cv2.putText(frame, "No faces detected", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
            else:
                # Draw rectangles around the faces
                for (top, right, bottom, left) in face_locations:
                    cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)

                # Compare the captured face with the existing photo
                face_found = False
                for face_encoding in face_encodings:
                    matches = face_recognition.compare_faces([existing_face_encoding], face_encoding, tolerance=0.4)  # Strict comparison

                    if matches[0]:
                        face_found = True
                        break

                # If a matching face is found, send True and exit
                if face_found:
                    print("True")  # Send True if faces match
                    break

            # Check if 2 seconds have passed since detection started
            if elapsed_time >= delay_time + 2:  # 2 seconds after detection starts
                cv2.putText(frame, "No match found", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
                cv2.imshow("Webcam", frame)
                cv2.waitKey(1000)  # Wait for 1 second to show the message
                break

        # Show the captured frame
        cv2.imshow("Webcam", frame)

        # Break the loop if the 'q' key is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release the webcam and close the window
    video_capture.release()
    cv2.destroyAllWindows()

except Exception as e:
    print(f"Error: {str(e)}")
    sys.exit(1)
