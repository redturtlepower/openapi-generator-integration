Const ForReading = 1
Const ForWriting = 2

strFileName = Wscript.Arguments(0)
strTempFile = strFileName & ".new"

Set objFSO = CreateObject("Scripting.FileSystemObject")
WScript.Echo ("opening input file " & strFileName )
WScript.Echo ("opening temp file " & strTempFile )
Set objInFile = objFSO.OpenTextFile(strFileName, ForReading)

If Not objFSO.FileExists(strTempFile) Then
    objFSO.CreateTextFile(strTempFile)
End If 
Set objOutFile = objFSO.OpenTextFile(strTempFile, ForWriting)

objOutFile.WriteLine("INCLUDEPATH += $$PWD/src $$PWD/src/handlers $$PWD/src/models $$PWD/src/requests")

prefix = "$$PWD/"
Do Until objInFile.AtEndOfStream
  line = LTrim(objInFile.ReadLine)

  If (LineStartsWith(line,"SOURCES")) Then  
    If (InStr(line,"main.cpp")) Then
      line = vbCrLf&"SOURCES += \"
    Else
      line = Replace(line, "SOURCES += ", vbCrLf&"SOURCES += \"&vbCrLf&prefix)
    End If
  ElseIf (LineStartsWith(line,"RESOURCES")) Then  
    line = Replace(line, "RESOURCES += ", vbCrLf&"RESOURCES += \"&vbCrLf&prefix)
  ElseIf (LineStartsWith(line,"HEADERS")) Then  
    line = Replace(line, "HEADERS += ", vbCrLf&"HEADERS += \"&vbCrLf&prefix)
  ElseIf (len(line)<>0) Then
    line = prefix & line
  End If
  line = Replace(line, "//", "/")

  objOutFile.WriteLine(line)
Loop

objInFile.Close
objOutFile.Close

objFSO.DeleteFile strFileName
objFSO.MoveFile strTempFile, strFileName

Function LineStartsWith(ByRef strLine, ByRef strWord)
  LineStartsWith = InStr(strLine,strWord)=1
End Function