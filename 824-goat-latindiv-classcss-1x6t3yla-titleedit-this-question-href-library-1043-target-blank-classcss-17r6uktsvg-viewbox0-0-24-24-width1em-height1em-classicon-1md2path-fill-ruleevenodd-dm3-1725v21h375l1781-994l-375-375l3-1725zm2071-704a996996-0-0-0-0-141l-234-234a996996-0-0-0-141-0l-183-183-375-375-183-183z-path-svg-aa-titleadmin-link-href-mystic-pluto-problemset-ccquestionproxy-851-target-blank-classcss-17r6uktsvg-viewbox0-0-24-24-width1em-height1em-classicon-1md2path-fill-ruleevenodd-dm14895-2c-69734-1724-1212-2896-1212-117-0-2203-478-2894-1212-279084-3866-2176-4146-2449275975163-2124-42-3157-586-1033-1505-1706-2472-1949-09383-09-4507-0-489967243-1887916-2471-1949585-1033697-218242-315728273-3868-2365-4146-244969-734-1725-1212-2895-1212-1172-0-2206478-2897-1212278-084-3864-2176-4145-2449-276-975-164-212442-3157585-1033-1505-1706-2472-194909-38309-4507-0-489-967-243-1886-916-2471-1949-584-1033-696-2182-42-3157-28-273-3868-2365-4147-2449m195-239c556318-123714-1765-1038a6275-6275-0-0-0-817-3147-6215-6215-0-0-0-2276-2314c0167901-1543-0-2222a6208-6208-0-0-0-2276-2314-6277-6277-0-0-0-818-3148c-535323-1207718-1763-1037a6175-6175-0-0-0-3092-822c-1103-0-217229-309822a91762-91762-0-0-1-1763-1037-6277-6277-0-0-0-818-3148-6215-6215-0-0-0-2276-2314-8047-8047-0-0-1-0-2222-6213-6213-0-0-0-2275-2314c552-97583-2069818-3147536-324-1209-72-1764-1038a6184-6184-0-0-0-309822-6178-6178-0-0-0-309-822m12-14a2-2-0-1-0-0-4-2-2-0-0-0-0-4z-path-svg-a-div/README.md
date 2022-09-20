<h2><a href="https://leetcode.com/problems/goat-latin/">824. Goat Latin<div class="css-1x6t3yl"><a title="Edit this question" href="/library/1043" target="_blank" class="css-17r6ukt"><svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M3 17.25V21h3.75L17.81 9.94l-3.75-3.75L3 17.25zM20.71 7.04a.996.996 0 0 0 0-1.41l-2.34-2.34a.996.996 0 0 0-1.41 0l-1.83 1.83 3.75 3.75 1.83-1.83z"></path></svg></a><a title="Admin link" href="/mystic/pluto/problemset/ccquestionproxy/851" target="_blank" class="css-17r6ukt"><svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M14.895 2c-.69.734-1.724 1.212-2.896 1.212-1.17 0-2.203-.478-2.894-1.212-.279.084-3.866 2.176-4.146 2.449.275.975.163 2.124-.42 3.157-.586 1.033-1.505 1.706-2.472 1.949-.09.383-.09 4.507 0 4.89.967.243 1.887.916 2.471 1.949.585 1.033.697 2.182.42 3.157.28.273 3.868 2.365 4.146 2.449.69-.734 1.725-1.212 2.895-1.212 1.172 0 2.206.478 2.897 1.212.278-.084 3.864-2.176 4.145-2.449-.276-.975-.164-2.124.42-3.157.585-1.033 1.505-1.706 2.472-1.949.09-.383.09-4.507 0-4.89-.967-.243-1.886-.916-2.471-1.949-.584-1.033-.696-2.182-.42-3.157-.28-.273-3.868-2.365-4.147-2.449m.195 2.39c.556.318 1.23.714 1.765 1.038a6.275 6.275 0 0 0 .817 3.147 6.215 6.215 0 0 0 2.276 2.314c.01.679.01 1.543 0 2.222a6.208 6.208 0 0 0-2.276 2.314 6.277 6.277 0 0 0-.818 3.148c-.535.323-1.207.718-1.763 1.037a6.175 6.175 0 0 0-3.092-.822c-1.103 0-2.172.29-3.09.822a91.762 91.762 0 0 1-1.763-1.037 6.277 6.277 0 0 0-.818-3.148 6.215 6.215 0 0 0-2.276-2.314 80.47 80.47 0 0 1 0-2.222 6.213 6.213 0 0 0 2.275-2.314c.552-.975.83-2.069.818-3.147.536-.324 1.209-.72 1.764-1.038a6.184 6.184 0 0 0 3.09.822 6.178 6.178 0 0 0 3.09-.822M12 14a2 2 0 1 0 0-4 2 2 0 0 0 0 4z"></path></svg></a></div></a></h2><h3>Easy</h3><hr><div><p>You are given a string <code>sentence</code> that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.</p>

<p>We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:</p>

<ul>
	<li>If a word begins with a vowel (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, or <code>'u'</code>), append <code>"ma"</code> to the end of the word.

	<ul>
		<li>For example, the word <code>"apple"</code> becomes <code>"applema"</code>.</li>
	</ul>
	</li>
	<li>If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add <code>"ma"</code>.
	<ul>
		<li>For example, the word <code>"goat"</code> becomes <code>"oatgma"</code>.</li>
	</ul>
	</li>
	<li>Add one letter <code>'a'</code> to the end of each word per its word index in the sentence, starting with <code>1</code>.
	<ul>
		<li>For example, the first word gets <code>"a"</code> added to the end, the second word gets <code>"aa"</code> added to the end, and so on.</li>
	</ul>
	</li>
</ul>

<p>Return<em> the final sentence representing the conversion from sentence to Goat Latin</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> sentence = "I speak Goat Latin"
<strong>Output:</strong> "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> sentence = "The quick brown fox jumped over the lazy dog"
<strong>Output:</strong> "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 150</code></li>
	<li><code>sentence</code> consists of English letters and spaces.</li>
	<li><code>sentence</code> has no leading or trailing spaces.</li>
	<li>All the words in <code>sentence</code> are separated by a single space.</li>
</ul>
</div>