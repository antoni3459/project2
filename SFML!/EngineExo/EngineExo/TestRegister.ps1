param(
    [Parameter()]
    [string]$path
)

$assemblyPath = $path + "\Assembly.h"
$str = "#pragma once`n"
$str += "#include `"Engine/Utils/ObjectMacro.h`"`n"

function ReplaceStr
{
    param([string]$str, [string[]]$toReplace, [string]$to)
    $count = $toReplace.Count
    for ($i = 0; $i -lt $toReplace.Count; $i = $i + 1)
    {
        $str = $str.Replace($toReplace[$i], $to)
    }
    return $str
}

function AddNamespace
{
    param([string]$str, [string[]]$toReplace, [string]$to)
    $count = $toReplace.Count
    for ($i = 0; $i -lt $toReplace.Count; $i = $i + 1)
    {
        $str = $str.Replace($toReplace[$i], $to)
    }
    return $str
}

Get-ChildItem $path -Recurse -Filter *.h |
        ForEach-Object {

            $scriptPath = $_.FullName

            $className = (Get-Item $scriptPath).BaseName
            $filecontents = Get-Content -Path $scriptPath
            $finalPath = ReplaceStr -str $scriptPath -toReplace "C:\Users\PRAIT2401\Desktop\project2\project2\SFML!\EngineExo\EngineExo\" -to ""
            $isPublic = $false
            $isNoTemplate = $true

            for ($i = 0; $i -lt $filecontents.Count; $i = $i + 1)
            { 
                $line = $filecontents[$i]
                if($line -match "public")
                {
                    $isPublic = $true
                }

                if($line -match "template")
                {
                    $isNoTemplate = $false
                }
            }

            if($isPublic -and $isNoTemplate)
            {
                $str += "#include `"$finalPath`"`n"
                $str +="REGISTER_TYPE("
                for ($i = 0; $i -lt $filecontents.Count; $i = $i + 1)
                { 
                    $line = $filecontents[$i]
                    if($line -match "namespace")
                    {

                    }
                }
                $str += "$className)`n"
                
            }
        }


$str | out-File $assemblyPath