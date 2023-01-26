Param(
    [parameter()]
    [String]$path
)
#uhfedhg
Write-Output "Path: $path"

$scriptPath = $path + "/Test/A.h"
$fileContents = Get-Content -Path $scriptPath
$isPublic = $false
$isObject = $false

$flags = ""
Get-ChildItem $path -Recurse -Filter *.h |
    Foreach-Object
{
    function IsPublic
    {
        param (
            [string]$line,
            [bool]$result
        )
    
        if ($line.Contains("public: "))
        {
            return $true
        }
        elseif ($line.Contains("private: ") -or $line.Contains("protected: "))
        {
            return $false
        }
        return $result
    }
    
    function AddFlag
    {
        param([string]$currentFlag,[string]$newFlag)
    
        if($currentFlag.Contains($newFlag))
        {
            return $currentFlag
        }
        if([string]::IsNullOrEmpty($currentFlag))
        {
            return "BindingFlags::$newFlag"
        }
        return "$currentFlag | BindingFlags::$newFlag"
    }
    
    function ReplaceStr
    {
        param([string]$str,[string[]]$toReplace,[string]$to)
        for ($i = 0; $i -lt $toReplace.Count; $i = $i + 1)
        {
            $str=$str.Replace($toReplace[$i],$to)
        }
        return $str
    }
    
    for ($i = 0; $i -lt $fileContents.Count; $i = $i + 1)
    {
        $line = $fileContents[$i]
    
        if($line -match "UPROPERTY\(\)" -and $line -notmatch "#define UPROPERTY\(...\)")
        {
            $isObject = $true
        }
    
        if([string]::IsNullOrEmpty($line))
        {
            continue
        }
    
        $isPublic = IsPublic -line $line -result $isPublic
    
        if($line -match "UPROPERTY\(\)")
        {
            $flags = ""
            if($isPublic)
            {
                $flags = AddFlag -currentFlag $flags -newFlag "Public"
            }
            else
            {
                $flags = AddFlag -currentFlag $flags -newFlag "NoPublic"
    
            }
            if($line.Contains("static"))
            {
                $flags = AddFlag -currentFlag $flags -newFlag "Static"
            }
            $isPointer = $line.Contains("*")
    
            #$field = $line.Replace("inline", "").Replace("const", "").Replace("static", "").Replace("constexpr", "")
            #$field = $field.Replace("UPROPERTY()", "").TrimStart()
            $field = ReplaceStr -str $line -toReplace @("inline", "const","static","constexpr","UPROPERTY()") -to ""
            $field = $field.TrimStart()
            $field = $field.Substring($field.IndexOf(' ') + 1)
            $field = $field.Substring(0, $field.IndexOf(' ')).Trim()
    
            $result = ""
            if($isPointer)
            {
                $result = "REGISTER_FIELD($field, $field, $flags)"
            }
            else
            {
                $result = "REGISTER_FIELD($field, &$field, $flags)"
            }
    
            $file = (Get-Content $scriptPath) -as [Collections.ArrayList]
            if($fileContents[$i +1] -match "REGISTER_FIELD")
            {
               $file.RemoveAt($i + 1)   
               $file.Insert($i + 1, $result)
            }
            else
            {
               $file.Insert($i + $indexFile + 1, $result)
               $indexFile = $indexFile + 1
            }
            $file | Set-Content $scriptPath
        }
    
    }
    for($i = 0; $i -lt $fileContents.Count; $i = $i +1)
    {
        if($line -match "REGISTER_FIELD" -and $fileContents[$i + 1] -notmatch "UPROPERTY")
        {
            $file = (Get-Content $scriptPath) -as [Collections.ArrayList]
            $file.RemoveAt($i)
            $file | Set-Content $scriptPath
        }
    }
}

 #$str | Out-File $fullPath
# 