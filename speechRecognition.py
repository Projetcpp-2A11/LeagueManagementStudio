import speech_recognition as sr
import threading



def recognize_speech():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:

        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source,timeout=5,phrase_time_limit=5)


        try:
            text = recognizer.recognize_google(audio).strip()
            return text.replace(" ","")

        except sr.UnknownValueError:
            return "ERROR: Could not understand audio"
        except sr.RequestError:
            return "ERROR: Could not request results"

if __name__ == "__main__":
    result= recognize_speech()
    print(result)
