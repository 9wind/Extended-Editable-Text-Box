// Włodzimierz Iwanowski 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableTextBox.h"
#include "MyEditableTextBox.generated.h"

UCLASS(meta = (DisplayName = "Extended Editable Text Box"))
class MYPROJECT_API UMyEditableTextBox : public UEditableTextBox
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Extendable Widget")
	bool bIsNumericOnly;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Extendable Widget", meta = (InlineEditConditionToggle))
	bool CapCharacterNumbers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Extendable Widget", meta = (EditCondition = "CapCharacterNumbers"))
	int32 CappedCharacterNumbers;

	virtual void HandleOnTextChanged(const FText& Text) override;


protected:


#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
};
