int main(){
    path input = ."/home/jader/files/*.txt";
    path output = .".";
    crunch (input $!("s/cat/dog/g") output);

    while (path p in input) {
        int i = 1;
        /*crunch(p $> _"/home/jader/files/alltxt.txt");*/
    }
    return 0;
}
