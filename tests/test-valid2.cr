int main(int argv, char argc){
    path input = ."/home/jader/files/*.txt";
    path output = .".";
    crunch (input $!("s/cat/dog/g") output);
    int i = 0;
    float a = 3.4e-3;
    string str="abcde";

    i = i + 1;

    while (i < 3) {
        i = i + 1;
        crunch(p $> _"/home/jader/files/alltxt.txt");
    }

    if (i == 3) {
        i = 4;
    }
    else {
        i = 5;
    }

    for (path p in input) {
        i = i + 1;
        printf("a", p);
    }
    return 0;
}
