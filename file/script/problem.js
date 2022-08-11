function gettags(texts,color){
	var result="";
	for(var i=0;i<texts.length;i++){
		if(i)result=result+"&nbsp;";
		result=result+"<span class='tag' style='background: "+color+"; display: inline-block; line-height: 17.25px;'>"+texts[i]+"</span>";
	}
	return result;
}
function difficulty(x){
	if(x==0)return "<span class='tag difficult-tag' style='background: #bfbfbf;' onclick='window.location.href=\"/problems?difficulty=0\";'>暂未评定</span>";
	if(x==1)return "<span class='tag difficult-tag' style='background: #fe4c61;' onclick='window.location.href=\"/problems?difficulty=1\";'>入门</span>";
	if(x==2)return "<span class='tag difficult-tag' style='background: #f39c11;' onclick='window.location.href=\"/problems?difficulty=2\";'>普及-</span>";
	if(x==3)return "<span class='tag difficult-tag' style='background: #ffc116;' onclick='window.location.href=\"/problems?difficulty=3\";'>普及/提高-</span>";
	if(x==4)return "<span class='tag difficult-tag' style='background: #52c41a;' onclick='window.location.href=\"/problems?difficulty=4\";'>普及+/提高</span>";
	if(x==5)return "<span class='tag difficult-tag' style='background: #3498db;' onclick='window.location.href=\"/problems?difficulty=5\";'>提高+/省选-</span>";
	if(x==6)return "<span class='tag difficult-tag' style='background: #9d3dcf;' onclick='window.location.href=\"/problems?difficulty=6\";'>省选/NOI-</span>";
	if(x==7)return "<span class='tag difficult-tag' style='background: #11207e;' onclick='window.location.href=\"/problems?difficulty=7\";'>NOI/NOI+</span>";
	if(x==8)return "<span class='tag difficult-tag' style='background: #052242;' onclick='window.location.href=\"/problems?difficulty=8\";'>CTSC/IOI</span>";
}
