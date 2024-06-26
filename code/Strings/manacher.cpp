// f = 1 para pares, 0 impar
//a a a a a a
//1 2 3 3 2 1   f = 0 impar
//0 1 2 3 2 1   f = 1 par (raiz, izq, der)
void manacher(string &s, int f, vi &d){
	int l=0, r=-1, n=sz(s);
	d.assign(n,0);
	for(int i=0;i<n;++i){
		int k=(i>r?(1-f):min(d[l+r-i+ f], r-i+f))+f;
		while(i+k-f<n && i-k>=0 && s[i+k-f]==s[i-k])++k;
		d[i]=k-f;--k;
		if(i+k-f>r)l=i-k,r=i+k-f;
	}
	for(int i=0;i<n;++i)d[i]=(d[i]-1+f)*2+1-f;
}

string s;
vi manacher_odd, manacher_even;
manacher(s, 0, manacher_odd);
manacher(s, 1, manacher_even);
for(int i=0;i<sz(s);++i)cout<<manacher_odd[i]<<" ";
cout<<"\n";
for(int i=0;i<sz(s);++i){
	if(manacher_odd[i]==0 || manacher_odd[i]==1)continue;
	cout<<s.substr(i-manacher_odd[i]/2, manacher_odd[i])<<" ";
}
cout<<"\n";
for(int i=0;i<sz(s);++i)cout<<manacher_even[i]<<" ";
cout<<"\n";
for(int i=0;i<sz(s);++i){
	if(manacher_even[i]==0)continue;
	cout<<s.substr(i-manacher_even[i]/2, manacher_even[i])<<" ";
}
cout<<"\n";