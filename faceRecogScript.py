import face_recognition
import json
import os
import sys

# Define paths (adjust these to your project structure)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
TMP_IMG_PATH = os.path.join(BASE_DIR, "tmp", "tmp.jpg")
ENCODINGS_FILE = os.path.join(BASE_DIR, "face_encodings.json")

def load_stored_encodings():
    if os.path.exists(ENCODINGS_FILE):
        try:
            with open(ENCODINGS_FILE, "r") as f:
                return json.load(f)
        except Exception as e:
            print(f"Error reading JSON: {e}")
            return []
    else:
        print("No encoding JSON file found.")
        return []

def authenticate_face(tolerance=0.4):
    # Verify that the temporary image exists
    if not os.path.exists(TMP_IMG_PATH):
        print("No match")
        sys.exit(1)

    # Load temporary image and compute its encoding
    unknown_image = face_recognition.load_image_file(TMP_IMG_PATH)
    unknown_encodings = face_recognition.face_encodings(unknown_image)
    if not unknown_encodings:
        print("No match")
        sys.exit(1)
    unknown_encoding = unknown_encodings[0]

    # Load the stored face encodings from JSON
    stored_data = load_stored_encodings()
    if not stored_data:
        print("No match")
        sys.exit(1)

    best_match_id = None
    best_distance = float("inf")

    # Iterate over each stored encoding entry from JSON
    for entry in stored_data:
        # Make sure the entry has the required keys
        if "user_id" not in entry or "encoding" not in entry:
            continue

        stored_encoding = entry["encoding"]
        # Compare using boolean match and check the distance
        matches = face_recognition.compare_faces([stored_encoding], unknown_encoding, tolerance=tolerance)
        distance = face_recognition.face_distance([stored_encoding], unknown_encoding)[0]

        if matches[0] and distance < best_distance:
            best_distance = distance
            best_match_id = entry["user_id"]

    if best_match_id:
        print(best_match_id)
        sys.exit(0)
    else:
        print("No match")
        sys.exit(1)

if __name__ == "__main__":
    try:
        authenticate_face()
    except Exception as e:
        # Fallback: Print "No match" in case of any unexpected error
        print("No match")
        sys.exit(1)
    finally:
                # Clean up: Delete the temporary image if it exists
                if os.path.exists(TMP_IMG_PATH):

                        os.remove(TMP_IMG_PATH)
                        # Optionally log deletion success:
                        #print("Temporary image {TMP_IMG_PATH} deleted.")

