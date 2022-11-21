# I have created this file
import string
from django.shortcuts import render


def index(request):
    return render(request, 'index.html')


def analyze(request):
   
    texted = request.POST.get('text', 'default')
    removepunc = request.POST.get('removepunc', 'off')
    fullcaps = request.POST.get('fullcaps', 'off')
    removenewline = request.POST.get('removenewline', 'off')
    removeextraspace = request.POST.get('removeextraspace', 'off')
    charcounter = request.POST.get('charcounter', 'off')

    analyzed = ""
    purpose = ""
    # Checkbox
    if removepunc == "on":
        # punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
        for char in texted:
            if char not in string.punctuation:
                analyzed = analyzed + char

        texted = analyzed
        purpose += " Removed punctuations. "
        # params = {'purpose': 'Removed puntuations', 'analyzed_text': analyzed}
        # return render(request, 'analyze.html', params)

    if fullcaps == "on":
        analyzed = ""
        for char in texted:
            analyzed = analyzed + char.upper()

        texted = analyzed
        purpose += " Changed to uppercase. "
        # params = {'purpose': 'Changed to uppercase', 'analyzed_text': analyzed}
        # return render(request, 'analyze.html', params)

    if removenewline == "on":
        analyzed = ""
        for char in texted:
            if char != '\n' and char != '\r':
                analyzed = analyzed + char
            # else:
            #     analyzed=analyzed + " "
        texted = analyzed
        purpose += " Removed newlines. "
        # params = {'purpose': 'Removed newlines', 'analyzed_text': analyzed}
        # return render(request, 'analyze.html', params)

    if removeextraspace == "on":
        analyzed = ""
        for ind, char in enumerate(texted):
            if not (texted[ind] == " " and texted[ind + 1] == " "):
                analyzed = analyzed + char
        texted = analyzed
        purpose += " Extra space removed. "
        # params = {'purpose': 'Extra space removed', 'analyzed_text': analyzed}
        # return render(request, 'analyze.html', params)

    if charcounter == "on":
        analyzed = ('Number of characters in the text are : ' + str(len(texted)))
        # for index, char in enumerate(texted):
        #     if not(texted[index] ==" " and texted[index+1]==" "):
        #         analyzed=analyzed + char
        purpose += " Length counter. "
        # params = {'purpose': 'Length counter', 'analyzed_text': analyzed}
        # return render(request, 'analyze.html', params)
    if (
            removepunc == "on" or fullcaps == "on" or removenewline == "on" or removeextraspace == "on" or charcounter == "on"):
        params = {'purpose': purpose, 'analyzed_text': analyzed}
        return render(request, 'analyze.html', params)
    else:
        params = {'display': 'block', 'msg': 'Oops', 'error': 'Please check the checkbox'}
        return render(request, 'index.html', params)
