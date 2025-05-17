Set fso = CreateObject("Scripting.FileSystemObject")
Set sh = CreateObject("WScript.Shell")

Do
  If fso.FileExists("stop.txt") Then WScript.Quit
  sh.Run "cmd"
  WScript.Sleep 1000
Loop
