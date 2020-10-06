int main(){
    path input = ."/home/jader/files/*.txt";
    path output = .".";
    crunch (input $!("s/cat/dog/g") output);

    for (path p in input) {
        crunch(p $> _"/home/jader/files/alltxt.txt")
    }
    return 0;
}
