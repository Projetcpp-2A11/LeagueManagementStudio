import face_recognition
import json
import os
import sys

# Define paths
SCRIPT_DIR = "C:\\Users\\choua\\OneDrive\\Bureau\\Projet C++\\LMS"
IMG_DIR = os.path.join(SCRIPT_DIR, "img")
ENCODINGS_FILE = os.path.join(SCRIPT_DIR, "face_encodings.json")

def load_existing_encodings():
    if os.path.exists(ENCODINGS_FILE):
        try:
            with open(ENCODINGS_FILE, "r") as f:
                return json.load(f)
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON: {e}")
            return []
    return []

def save_encoding(user_id, image_path):
    if not os.path.exists(image_path):
        print(f"Image file not found: {image_path}")
        return

    try:
        image = face_recognition.load_image_file(image_path)
    except Exception as e:
        print(f"Error loading image: {e}")
        return

    try:
        encodings = face_recognition.face_encodings(image)
    except Exception as e:
        print(f"Error during face encoding: {e}")
        return

    if not encodings:
        print(f"No face encoding found in image: {image_path}")
        return

    print(f"Encoding found for image: {image_path}")
    existing_data = load_existing_encodings()

    # Option 1: Using a list if you plan multiple encodings per user
    new_data = {
        "user_id": user_id,
      "encoding": encodings[0].tolist()  # Convert NumPy array to a list
    }
    existing_data.append(new_data)

    # Option 2: Using a dictionary if you only want one encoding per user.
    #Uncomment the block below and comment the list approach above if desired.
    #existing_data = load_existing_encodings()
    #xisting_data[user_id] = encodings[0].tolist()

    try:
        with open(ENCODINGS_FILE, "w") as f:
            json.dump(existing_data, f, indent=4)
        print(f"Encoding for user {user_id} saved successfully!")
    except Exception as e:
        print(f"Error writing to JSON file: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("No user ID provided.")
        sys.exit(1)

    user_id = sys.argv[1]
    image_path = os.path.join(IMG_DIR, f"{user_id}.jpg")
    save_encoding(user_id, image_path)
