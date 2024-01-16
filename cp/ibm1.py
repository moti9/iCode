def parse_url_parameters(url):
    parameters = []
    query_start = url.find('?')
    if query_start != -1:
        query_string = url[query_start + 1:]
        for param in query_string.split('&'):
            parameters.append(param)
    return parameters

def validate_request(valid_tokens, request):
    request_type, url = request

    url_parameters = parse_url_parameters(url)

    token_param = next((param for param in url_parameters if param.startswith("token=")), None)
    if not token_param:
        return "INVALID"

    auth_token = token_param.split("=")[1]

    if auth_token not in valid_tokens:
        return "INVALID"

    if request_type == "POST":
        csrf_token_param = next((param for param in url_parameters if param.startswith("csrf=")), None)
        if not csrf_token_param or len(csrf_token_param.split("=")[1]) < 8 or not csrf_token_param.split("=")[1].isalnum():
            return "INVALID"

    result = "VALID,"
    for param in url_parameters:
        if "=" in param and param.startswith("name"):
            result += f"name,{param.split('=')[1]}"

    return result

def get_responses(valid_tokens, requests):
    results = [validate_request(valid_tokens, request) for request in requests]
    return results

if __name__ == "__main__":
    # Example usage:
    valid_tokens = ["ah37j2ha483u", "safh34ywb0p5", "ba34wyi8t902"]
    requests = [
        ("GET", "https://example.com/?token=347sd6yk8iu2&name=alex"),
        ("GET", "https://example.com/?token=safh34ywb0p5&name=sam"),
        ("POST", "https://example.com/?token=safh34ywb0p5&name=alex"),
        ("POST", "https://example.com/?token=safh34ywb0p5&csrf=ak2sh32dy&name=chris")
    ]

    results = get_responses(valid_tokens, requests)

    for result in results:
        print(result)
