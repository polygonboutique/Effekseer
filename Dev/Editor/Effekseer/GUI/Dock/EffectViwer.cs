﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Effekseer.GUI.Dock
{
	class EffectViwer : DockPanel
	{
		public bool IsHovered = false;



		Component.Enum renderMode;
		Component.Enum viewMode;

		public EffectViwer()
		{
			Label = Resources.GetString("Viewer") + "###Viewer";
			renderMode = new Component.Enum();
			renderMode.Initialize(typeof(Data.OptionValues.RenderMode));
			renderMode.SetBinding(Core.Option.RenderingMode);
			renderMode.EnableUndo = false;
			viewMode = new Component.Enum();
			viewMode.Initialize(typeof(Data.OptionValues.ViewMode));
			viewMode.SetBinding(Core.Option.ViewerMode);
			viewMode.EnableUndo = false;

			NoPadding = true;
			NoScrollBar = true;
			NoCloseButton = true;
			AllowsShortTab = false;
		}

		protected override void UpdateInternal()
		{
			float dpiScale = Manager.DpiScale;

			IsHovered = false;

			var contentSize = Manager.NativeManager.GetContentRegionAvail();

			// Menu
			contentSize.X = System.Math.Max(1, contentSize.X);
			contentSize.Y = System.Math.Max(1, contentSize.Y - 30 * dpiScale);

			var p = Manager.Native.RenderView((int)contentSize.X, (int)contentSize.Y);
			Manager.NativeManager.Image(p, (int)contentSize.X, (int)contentSize.Y);

			IsHovered = Manager.NativeManager.IsWindowHovered();

			Manager.NativeManager.Indent(4 * dpiScale);

			// Enum
			Manager.NativeManager.PushItemWidth(120 * dpiScale);
			renderMode.Update();
			Manager.NativeManager.PopItemWidth();

			Manager.NativeManager.SameLine();

			Manager.NativeManager.PushItemWidth(50 * dpiScale);
			viewMode.Update();
			Manager.NativeManager.PopItemWidth();

			string perfText = 
				"D:" + Manager.Native.GetAndResetDrawCall().ToString("D3") + "  " + 
				"V:" + Manager.Native.GetAndResetVertexCount().ToString("D5") + "  " +
				"P:" + Manager.Native.GetInstanceCount().ToString("D5") + " ";

			Manager.NativeManager.SameLine(contentSize.X - Manager.NativeManager.CalcTextSize(perfText).X);

			// Display performance information
			Manager.NativeManager.Text(perfText);
			if (Manager.NativeManager.IsItemHovered())
			{
				Manager.NativeManager.SetTooltip(
					"D: Draw calls of current rendering.\n" +
					"V: Vertex count of current rendering.\n" +
					"P: Particle count of current rendering.");
			}
		}
	}
}
