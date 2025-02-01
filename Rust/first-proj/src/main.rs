fn main() {
    
    let sentence = String::from("Welcome to the rust programming");

    let word = find_first_word(sentence);

    for i in 1..101{
        println!("Hello world - {}", i);
    }

    println!("First word : {}", word);


}

fn find_first_word(sentence: String) -> String {
    let mut word = String::from("");

    for ch in sentence.chars(){
        if ch == ' '{
            break;
        }
        word.push_str(ch.to_string().as_str());
    }
    return word;
}
