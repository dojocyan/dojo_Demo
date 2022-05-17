// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class DojoChain.ChainForUnrealTarget : TargetRules
{
	public DojoChain.ChainForUnrealTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "DojoChain.ChainForUnreal" } );
	}
}
