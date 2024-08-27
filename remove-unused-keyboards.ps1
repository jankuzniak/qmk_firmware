$keyboards = Get-ChildItem ".\keyboards" -Directory
$myKeyboards = "crkbd","gboards","sofle"

Write-Output $path

foreach($k in $keyboards) {
	if (!$myKeyboards.contains($k.Name)) {
		$path = ".\keyboards\" + $k.Name
		git rm -r -f $path | Out-Null
		Remove-Item -Path $path -Recurse
	}
}
