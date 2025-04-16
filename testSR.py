import speech_recognition as sr

def recognize_speech():
    recognizer = sr.Recognizer()

    with sr.Microphone() as source:
        print("Recording... Speak now.")
        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source)

    try:
        text = recognizer.recognize_google(audio).strip()  # Trim spaces
        print(text)  # Output the text to stdout (Qt will capture this)
    except sr.UnknownValueError:
        print("ERROR: No speech recognized")
    except sr.RequestError:
        print("ERROR: Failed to connect to Google STT")

if __name__ == "__main__":
    recognize_speech()
