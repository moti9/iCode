import os
import google.auth.transport.requests
import google_auth_oauthlib.flow
from google.oauth2.credentials import Credentials
from googleapiclient.discovery import build
from googleapiclient.http import MediaFileUpload

SCOPES = ['https://www.googleapis.com/auth/drive']
CLIENT_SECRET_FILE = "credentials.json"
# REDIRECT_URI = 'https://dev.ottermap.com/'

def get_credentials():
    creds = None
    if os.path.exists("token.json"):
        creds = Credentials.from_authorized_user_file("token.json", SCOPES)
    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(google.auth.transport.requests.Request())
        else:
            flow = google_auth_oauthlib.flow.InstalledAppFlow.from_client_secrets_file(
                CLIENT_SECRET_FILE, SCOPES)
            creds = flow.run_local_server(port=8000)
        with open("token.json", "w") as token:
            token.write(creds.to_json())
    return creds

def create_folder_and_upload():
    creds = get_credentials()
    drive_service = build('drive', 'v3', credentials=creds)

    folder_metadata = {
        "name": "TestMapImage",
        "mimeType": "application/vnd.google-apps.folder"
    }

    folder = drive_service.files().create(body=folder_metadata, fields="id").execute()
    folder_id = folder.get("id")

    file_metadata = {
        "name": "pixel_matrix.txt",
        "parents": [folder_id]  # Fix key from 'parent' to 'parents'
    }

    media = MediaFileUpload("pixel_matrix.txt", mimetype='text/plain')
    file = drive_service.files().create(body=file_metadata, media_body=media, fields="id").execute()

    file_id = file.get("id")

    permission = {
        'type': 'anyone',
        'role': 'reader'
    }

    drive_service.permissions().create(fileId=file_id, body=permission).execute()

    public_url = f"https://drive.google.com/file/d/{file_id}/view?usp=sharing"

    return public_url

public_url = create_folder_and_upload()
print(public_url)
