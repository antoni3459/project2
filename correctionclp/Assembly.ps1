Param(
    [parameter()]
    [String]$path
)

$assemblyPath = $path + "\Assembly.h"
$str = "#pragma once`n"
$str += "#include `"Domain/AppDomain.h`"`n"

Write-Output "test"
Write-Output $assemblyPath

Get-ChildItem $path -Recurse -Filter *.h | 
    Foreach-Object{
        $fullPath = $_.FullName
        $className = (Get-Item $fullPath).BaseName
        $includePath = $fullPath.Replace($path, "")
       # $includePath = $includePath.Substring(0, $includePath.Lenght)
        $includePath = $includePath.Replace("\", "/")

        $isObject = $false
        Foreach($line in Get-Content $fullPath)
        {
            if ($line -match "UCLASS")
            {
                $isObject = $true
            }
        }
        if ($isObject)
        {
            Write-Output $className
            $str += "#include `"$includePath`"`n"
            $str += "REGISTER_CLASS($className)`n"
        }
    }

    $str | out-File $assemblyPath