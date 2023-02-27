// Włodzimierz Iwanowski 2023


#include "MyEditableTextBox.h"


#define LOCTEXT_NAMESPACE "UMG"




void UMyEditableTextBox::HandleOnTextChanged(const FText& InText)
{
	FText ModifiedText = InText;
	
	if (bIsNumericOnly)
	{
		FString Checker = ModifiedText.ToString();
		if (!Checker.IsNumeric())
		{
			Checker = Checker.LeftChop(1);
			ModifiedText = FText::FromString(Checker);
			SetText(ModifiedText);
		}
	}

	if (CapCharacterNumbers)
	{
		FString Checker = ModifiedText.ToString();
		if (Checker.Len() > CappedCharacterNumbers)
		{
			Checker = Checker.LeftChop(1);
			ModifiedText = FText::FromString(Checker);
			SetText(ModifiedText);
		}
	}

	Text = ModifiedText;
	OnTextChanged.Broadcast(ModifiedText);
}


#if WITH_EDITOR
const FText UMyEditableTextBox::GetPaletteCategory()
{
	return LOCTEXT("Asset", "Asset");
}
#endif
