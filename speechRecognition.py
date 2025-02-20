import speech_recognition as sr
import cv2
import threading



def recognize_speech():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        #print("Listening...")

        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source)

        cv2.destroyAllWindows()  # Close the microphone image

        try:
            text = recognizer.recognize_google(audio).strip()
            print(text)
        except sr.UnknownValueError:
            print("ERROR: Could not understand audio")
        except sr.RequestError:
            print("ERROR: Could not request results")

if __name__ == "__main__":
    recognize_speech()
