Param(
    [parameter()]
    [String]$path
)
$str = ""
#Get-ChildItem $path -Recurse -Filter *.h | 
#    Foreach-Object{
        $fullpath = "test.h"
        $className = (Get-Item $fullpath).BaseName

        $isProperty = $false
        $isFunction = $false
        $isObject = $false
        foreach($line in Get-Content $fullPath)
        {
            
            $str += $line + "`n"

            if ($line -match "UCLASS")
            {
                $isObject = $true
                
                if ($isObject -and $line -match "UPROPERTY")
                {
                    $isProperty = $true
                    if ($isProperty)
                    {
                        Write-Output $className
                        $str += "REGISTER_FIELD($className) `n"
                    }
                }
                if ($isObject -and $line -match "UFUNCTION")
                {
                   $isFunction = $true
                   if ($isFunction)
                   {
                       Write-Output $className
                       $str += "REGISTER_METHOD($className) `n"
                   }
                }
                if ($isProperty)
                {
                    Write-Output $className
                    $str += "REGISTER_FIELD($className) `n"
                }
            }
        }
    #} 
$str | Out-File $fullPath