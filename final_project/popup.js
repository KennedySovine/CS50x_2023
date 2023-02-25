const text = document.querySelectorAll('h1, h2, h3, h4, h5, p, li, td, caption, span, a, p, sup, span, dd, li');

for (let i = 0; i < text.length; i++) {
    if (text[i].innerHTML.includes('awesome')) {
        text[i].innerHTML = text[i].innerHTML.replace('awesome', 'poggers');
    }
    if (text[i].innerHTML.includes('cool')) {
        text[i].innerHTML = text[i].innerHTML.replace('cool', 'poggers');
    }
    if (text[i].innerHTML.includes('Awesome')) {
        text[i].innerHTML = text[i].innerHTML.replace('Awesome', 'Poggers');
    }
    if (text[i].innerHTML.includes('Cool')) {
        text[i].innerHTML = text[i].innerHTML.replace('Cool', 'Poggers');
    }
    if (text[i].innerHTML.includes('awe')) {
        text[i].innerHTML = text[i].innerHTML.replace('awe', 'pog');
    }
    if (text[i].innerHTML.includes('lying')) {
        text[i].innerHTML = text[i].innerHTML.replace('lying', 'capping');
    }
    if (text[i].innerHTML.includes('money')) {
        text[i].innerHTML = text[i].innerHTML.replace('money', 'bits');
    }
    if (text[i].innerHTML.includes('cash')) {
        text[i].innerHTML = text[i].innerHTML.replace('cash', 'bits');
    }
    if (text[i].innerHTML.includes('video')) {
        text[i].innerHTML = text[i].innerHTML.replace('video', 'VOD');
    } else if (text[i].innerHTML.includes('videos')) {
        text[i].innerHTML = text[i].innerHTML.replace('videos', 'VODs');
    }
    if (text[i].innerHTML.includes('Videos')) {
        text[i].innerHTML = text[i].innerHTML.replace('Videos', 'VODs');
    } else if (text[i].innerHTML.includes('Video')) {
        text[i].innerHTML = text[i].innerHTML.replace('Video', 'VOD');
    }
    if (text[i].innerHTML.includes('support')) {
        text[i].innerHTML = text[i].innerHTML.replace('support', 'Prime');
    }
    if (text[i].innerHTML.includes('Support')) {
        text[i].innerHTML = text[i].innerHTML.replace('Support', 'Prime');
    }
    if (text[i].innerHTML.includes('images')) {
        text[i].innerHTML = text[i].innerHTML.replace('images', 'Emotes');
    } else if (text[i].innerHTML.includes('image')) {
        text[i].innerHTML = text[i].innerHTML.replace('image', 'emote');
    }
    if (text[i].innerHTML.includes('Images')) {
        text[i].innerHTML = text[i].innerHTML.replace('Images', 'Emotes');
    } else if (text[i].innerHTML.includes('Image')) {
        text[i].innerHTML = text[i].innerHTML.replace('Image', 'Emote');
    }
    if (text[i].innerHTML.includes('sad')) {
        text[i].innerHTML = text[i].innerHTML.replace('sad', 'sadge');
    }
    if (text[i].innerHTML.includes('Sad')) {
        text[i].innerHTML = text[i].innerHTML.replace('Sad', 'sadge');
    }
    if (text[i].innerHTML.includes('people')) {
        text[i].innerHTML = text[i].innerHTML.replace('people', 'gamers');
    }
    if (text[i].innerHTML.includes('People')) {
        text[i].innerHTML = text[i].innerHTML.replace('People', 'Gamers');
    }
    if (text[i].innerHTML.includes('persons')) {
        text[i].innerHTML = text[i].innerHTML.replace('persons', 'gamers');
    } else if (text[i].innerHTML.includes('person')) {
        text[i].innerHTML = text[i].innerHTML.replace('person', 'gamer');
    }
    if (text[i].innerHTML.includes('Persons')) {
        text[i].innerHTML = text[i].innerHTML.replace('Persons', 'Gamers');
    } else if (text[i].innerHTML.includes('Person')) {
        text[i].innerHTML = text[i].innerHTML.replace('Person', 'Gamer');
    }
    if (text[i].innerHTML.includes('photos')) {
        text[i].innerHTML = text[i].innerHTML.replace('photos', 'emotes');
    } else if (text[i].innerHTML.includes('photo')) {
        text[i].innerHTML = text[i].innerHTML.replace('photo', 'emote');
    }
    if (text[i].innerHTML.includes('Photos')) {
        text[i].innerHTML = text[i].innerHTML.replace('Photos', 'Emotes');
    } else if (text[i].innerHTML.includes('Photo')) {
        text[i].innerHTML = text[i].innerHTML.replace('Photo', 'Emote');
    }
}