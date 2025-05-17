Set sh = CreateObject("WScript.Shell")
Do
  sh.Run "cmd"
  WScript.Sleep 1000 ' 1000 ms = 1 seconde
Loop
