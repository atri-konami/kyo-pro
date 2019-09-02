n,b,c=gets.chomp.split.map(&:to_i);a=gets.chomp.split.map(&:to_i).reverse;if b==0;puts 0;exit;end;r=0;i=0;while(c>=b && i<n) do;r+=a[i]*b;c-=b;i+=1;end;if i<n;r+=a[i]*c;end;puts r
