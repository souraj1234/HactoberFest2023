class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
{
    // code here
    if(X == 0)
        return 0;

    int i, res{1};
    bool sig{false};
    
    for(int j{0}; j < adj[0].size(); j++){ // check if x comes whithin first lvl..
        if(adj[0][j] == X){
            return 1;
        }
    }
    for(i = 1; i < V; i++){ // finding x from 1 to v-1..
        for(int j{1}; j < adj[i].size(); j++){ // avoiding first elements of adj[i]..
            if(adj[i][j] == X){
                sig = true; // using sig as signal..
                break;
            }
        }
        if(sig) // break searching if signal is true
            break;
    }
    if(!sig) // return -1 if x not found
        return -1;
    
    while(i != 0){ // reverse count until we get to adj[0]...
        res++;
        i = adj[i][0];
    }
    return res;
}
};
